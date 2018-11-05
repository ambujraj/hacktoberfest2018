
/* I will add here every day one or two common js interview questions and there respective answers which would 
    help u gain confidence and also to ace or hone up your JS skills
*/
let obj = {
    a:5,
    b:function(){
        console.log(this.a);
    },
    c:()=>{
        console.log(this.a);
    }
};

let f1 = obj.b;
let f2 = obj.c;
f1();
f2();

obj.b();
obj.c();


//So, answer of this above four function calling will be as follows with their explanation =>

f1() // this will print "undefined" as in after obj.b, f1 is now referencing global object window not object obj
       // this.a will print undefined as with window object there is no a property defined. 
f2() // this will also print "undefined" as in arrow functions "this" will refer  "this" of surrounding scope
     // as in arrow function "this" doesn't not get bind so if we want to know the value of this we should see
     // the this just above the line we have start declaring our arrow function.Hence here "this" is referring to 
     // window object that's why it doesn't has any 'a' property defined with it.

obj.b() // here it will print '5' as in regular function calling b method will get bind to object left of dot

obj.c() // here also it will print "undefined" as in arrow function this doesn't get bind and it will see "this" of surrounding scope 
        // which is referring to window object and that object not have any 'a' property defined with it  