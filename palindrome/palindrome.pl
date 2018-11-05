#
# Palindrome in Perl
#
print "enter a num\n";
$n=<STDIN>;
$t=$n;
$s=0;
while($n>0)
{
$r=$n%10;
$s=($s*10)+$r;
$n=int($n/10);
}
if($t==$s)
{
print"Number is palindrome\n";
}
else
{
print"Number is not palindrome\n";
}