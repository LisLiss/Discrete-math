$a=5;
$n=5;
$a=($a+1)%$n;
$q="'";
$s='$a=; $n=5; $a=($a+1)%$n; $q=""; $s=; $d=$s; $d=~s/;[ ]/;\n/g; print substr($d,0,3).$a.substr($d,3, 26).$q.substr($d,29,6).$q.$s.$q.substr($d,35);';
$d=$s;
$d=~s/;[ ]/;\n/g;
print substr($d,0,3).$a.substr($d,3, 26).$q.substr($d,29,6).$q.$s.$q.substr($d,35);