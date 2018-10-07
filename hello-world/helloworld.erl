-module(helloworld).
-export([hello_world/0]).

hello_world() -> 
	io:fwrite("Hello world!\n").

% c(helloworld).
% helloworld:hello_world().
