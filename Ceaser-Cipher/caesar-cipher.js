var inputText = prompt('Please enter a message to encrypt or decrypt:', '(enter message here)');
var outputText = '';
var key = prompt('Please enter the KEY in which the message should be encrypted ou decrypted:', '(enter KEY here)');

for (var i = 0; i < inputText.length; i++) {
    var inputChar = inputText.charCodeAt(i);
    console.log(inputChar);
    var outputChar = +inputChar + +key;
    console.log(outputChar);
    outputText += String.fromCharCode(outputChar);
}

if (key > 0) {
	window.alert('Encrypted Message: ' + outputText + '\n\n(KEY for decryption: -' + key +')');
} else {
	window.alert('Decrypted Message: ' + outputText);
}