const primesList = (numa, numb) => {
 let check;
 let list = [];

 if (numa < 2) numa = 2;

 while (numb >= numa) {
    check = true;

    for ( let i = 2; i < numa; i++ ) {
      if ( numa % i === 0 ) {
        check = false;
        break;
      }
    }

    if (check) {
      list.push(numa);
    }

    numa++;
 }

 return list.toString();
}

primesList(1, 100);
