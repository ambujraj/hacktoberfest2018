var n, result
n = parseInt(prompt("number"))
result = fat(n)
alert(result)

function fat(n){
    if(n == 1){
      return 1;
    }
    return n*fat(n-1)
}
