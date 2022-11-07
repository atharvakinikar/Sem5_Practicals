create_stud(){
	echo "Enter File Name"
	read fn
	touch $fn
}

read_stud(){
	cat $fn
}

insert_stud(){
	echo "Roll Number : "
	read rno
	echo "Name : "
	read name
	echo "Total Marks : "
	read mark
	echo "$rno $name $mark">>$fn
}

delete_stud(){
	echo "Enter Roll Number To Be Deleted : "
	read rno
	grep -v "$rno" $fn >> temp
	mv temp $fn
}

modify_stud(){
	echo "Enter Roll Number To Be Modified : "
	read rno
	grep -v "$rno" $fn >> temp
	mv temp $fn
	echo "Roll Number : "
	read rno
	echo "Name : "
	read name
	echo "Total Marks : "
	read mark
	echo "$rno $name $mark">>$fn
}

while true
do
	echo "1.Create 2.Display 3.Insert 4.Delete 5.Modify"
	read ch
	case $ch in
		1)
		create_stud;;
		  
		2)
		read_stud;;
		
		3)
		insert_stud;;
		
		4)
		delete_stud;;
		
		5)
		modify_stud;;
		
		*)
		echo "Invalid Choice Entered"
		
	esac
done

exit