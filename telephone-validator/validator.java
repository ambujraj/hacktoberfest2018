public boolean validator(String number) {
  int num = Integer.parseInt(number);
  if( num != null || number.length() == 10 ){
    return true;
  }
  return false;
}