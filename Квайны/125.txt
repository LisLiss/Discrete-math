$a="beta";
$pr{"alpha"}="beta";
$pr{"beta"}="alpha";
$a=$pr{$a};
$q="'";
$s='$a=""; $pr{"alpha"}="beta"; $pr{"beta"}="alpha"; $a=$pr{$a}; $q=""; $s=; $d=$s; $d=~s/;[ ]/;\n/g; print substr($d,0,4).$a.substr($d,4, 61).$q.substr($d,65,6).$q.$s.$q.substr($d,71);';
$d=$s;
$d=~s/;[ ]/;\n/g;
print substr($d,0,4).$a.substr($d,4, 61).$q.substr($d,65,6).$q.$s.$q.substr($d,71);