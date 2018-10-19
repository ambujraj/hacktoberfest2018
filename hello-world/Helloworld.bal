import ballerina/http;

@http:ServiceConfig {
  basePath: "/"
}

//Bind a new service for port 9000
service<http:Service> hello bind {port:9000} {

//Only accept POST requests 
  @http:ResourceConfig {
      path: "/",
      methods: ["POST"]
  }
  //New resource named hello
  hello (endpoint caller, http:Request request) {

      http:Response res;
      res.setPayload("Hello World from Ballerina!");

      _ = caller->respond(res);
  }
}
