public boolean validator(String number) {
  String regex = "^\\+(?:[0-9] ?){6,14}[0-9]$";
  Pattern pattern = Pattern.compile(regex);
  Matcher matcher = pattern.matcher(email);
  return matcher.matches();
}