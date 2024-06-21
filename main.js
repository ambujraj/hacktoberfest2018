var array = [
    {name: "John", age: 34},
    {name: "Peter", age: 54},
    {name: "Jake", age: 25}
  ];
  
  array.sort(function(a, b) {
    return a.age - b.age;
  }); // Sort youngest first