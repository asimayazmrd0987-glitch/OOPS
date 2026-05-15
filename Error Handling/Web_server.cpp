#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

// ─── HTTP-style exceptions ──────────────────────────────────────────────
class HttpException : public runtime_error {
    int statusCode_;
public:
    HttpException(int code, const string& msg)
        : runtime_error(msg), statusCode_(code) {}
    int statusCode() const { return statusCode_; }
};
class NotFoundException      : public HttpException {
public: NotFoundException(const string& res)
    : HttpException(404, "Not Found: " + res) {}
};
class UnauthorizedException  : public HttpException {
public: UnauthorizedException()
    : HttpException(401, "Unauthorized: missing or invalid token") {}
};
class BadRequestException    : public HttpException {
public: BadRequestException(const string& reason)
    : HttpException(400, "Bad Request: " + reason) {}
};
class InternalServerException: public HttpException {
public: InternalServerException(const string& detail)
    : HttpException(500, "Internal Server Error: " + detail) {}
};

// ─── Request processing ──────────────────────────────────────────────────
struct Request { string method, path, token, body; };
struct Response { int status; string body; };

Response handleRequest(const Request& req) {
    if (req.token.empty())
        throw UnauthorizedException();
    if (req.method != "GET" && req.method != "POST")
        throw BadRequestException("Unsupported method: " + req.method);
    if (req.path == "/api/users")
        return {200, R"({"users":["ali","sara"]})"};
    if (req.path == "/api/admin")
        throw NotFoundException("/api/admin");
    throw NotFoundException(req.path);
}

// ─── Middleware-style exception handler ──────────────────────────────────
Response safeHandle(const Request& req) noexcept {
    try {
        return handleRequest(req);
    }
    catch (const HttpException& e) {
        return {e.statusCode(), string("Error: ") + e.what()};
    }
    catch (const exception& e) {
        return {500, string("Internal: ") + e.what()};
    }
    catch (...) {
        return {500, "Unknown server error"};
    }
}

int main() {
    vector<Request> requests = {
        {"GET",  "/api/users", "token123", ""},   // 200 OK
        {"GET",  "/api/users", "",          ""},   // 401
        {"GET",  "/api/admin", "token123", ""},   // 404
        {"POST", "/api/users", "token123", "{}"},  // 200 OK
        {"PUT",  "/api/data",  "token123", ""},   // 400 Bad Method
    };
    for (auto& req : requests) {
        auto res = safeHandle(req);
        cout << req.method << " " << req.path
             << " -> " << res.status << " " << res.body << "\n";
    }
}