
function validarCPF( cpf ){
var filtro = /^\d.\d.\d-\d$/i;

if(!filtro.test(cpf)){
window.alert("CPF inválido. Por favor corrija.");

return false;
}

cpf = remove(cpf, ".");
cpf = remove(cpf, "-");

if(cpf.length != 11 || cpf == "00000000000" || cpf == "11111111111" ||
cpf == "22222222222" || cpf == "33333333333" || cpf == "44444444444" ||
cpf == "55555555555" || cpf == "66666666666" || cpf == "77777777777" ||
cpf == "88888888888" || cpf == "99999999999")
{
window.alert("CPF inválido. Por favor corrija.");
return false;
}

soma = 0;
for(i = 0; i < 9; i++)
{
soma += parseInt(cpf.charAt(i)) * (10 - i);
}

resto = 11 - (soma % 11);
if(resto == 10 || resto == 11)
{
resto = 0;
}
if(resto != parseInt(cpf.charAt(9))){
window.alert("CPF inválido. Por favor corrija.");
return false;
}

soma = 0;
for(i = 0; i < 10; i ++)
{
soma += parseInt(cpf.charAt(i)) * (11 - i);
}
resto = 11 - (soma % 11);
if(resto == 10 || resto == 11)
{
resto = 0;
}

if(resto != parseInt(cpf.charAt(10))){
window.alert("CPF inválido. Por favor corrija.");
this.value = ""
return false;
}

return true;
}

function remove(str, sub) {
i = str.indexOf(sub);
r = "";
if (i == -1) return str;
{
r += str.substring(0,i) + remove(str.substring(i + sub.length), sub);
}

return r;
}

function mascara(o,f){
v_obj=o
v_fun=f
setTimeout("execmascara()",1)
}

function execmascara(){
v_obj.value=v_fun(v_obj.value)
}

function cpf_mask(v){
v=v.replace(/\D/g,"") //Remove tudo o que não é dígito
v=v.replace(/(\d)(\d)/,"$1.$2") //Coloca ponto entre o terceiro e o quarto dígitos
v=v.replace(/(\d)(\d)/,"$1.$2") //Coloca ponto entre o setimo e o oitava dígitos
v=v.replace(/(\d)(\d)/,"$1-$2") //Coloca ponto entre o decimoprimeiro e o decimosegundo dígitos
return v
}