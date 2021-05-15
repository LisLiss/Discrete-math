$a=4;
$a++;
$q="'";
$s='$a=; $a++; $q=""; $s=; $d=$s; $d=~s/;[ ]/;\n/g; print substr($d,0,3).$a.substr($d,3,12).$q.substr($d,15,6).$q.$s.$q.substr($d,21);';
$d=$s;
$d=~s/;[ ]/;\n/g;
print substr($d,0,3).$a.substr($d,3,12).$q.substr($d,15,6).$q.$s.$q.substr($d,21);