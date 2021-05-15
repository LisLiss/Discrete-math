$a=1;
if ($a==1) { print "";
} else{ $a--;
$q="'";
$s='$a=; if ($a==1) { print ""; } else{ $a--; $q=""; $s=; $d=$s; $d=~s/;[ ]/;\n/g; print substr($d,0,3).$a.substr($d,3,43).$q.substr($d,46,6).$q.$s.$q.substr($d,52); }';
$d=$s;
$d=~s/;[ ]/;\n/g;
print substr($d,0,3).$a.substr($d,3,43).$q.substr($d,46,6).$q.$s.$q.substr($d,52);
}