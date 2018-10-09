const isPanagram = (value) => {
  const characterArray = [];
  for(let i = 0; i < 26; i++)
    characterArray.push(0);
  
  const lowerCasedString = value.toLowerCase();
  for(let i = 0; i < lowerCasedString.length; i++) {
    const charCode = lowerCasedString.charCodeAt(i) - 97;
    characterArray[charCode] += 1;
  }

  for(let i = 0; i < characterArray.length; i++) {
    if(characterArray[i] === 0)
      return false;
  }

  return true;
}

const panagram = isPanagram("The Quick Brown Fox Jumps Over The Lazy Dog");
if(panagram)
  console.log('The given string is a panagram');
else
  console.log('The given string is not a panagram');
