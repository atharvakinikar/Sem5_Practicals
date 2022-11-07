#!/bin/sh
#Assignment 1 - address book using shell scripting

create()
{
		echo "Enter  address book name"
		read ab
		#check address book is available
		res=`ls | grep $ab | wc -w`
		
		if [ $res -gt 0 ]
		then
				echo "Error: File already exists"
		else
				touch $ab
				echo "Address Book created!"
		fi
}	

display()
{
		echo "Enter address book name"
		read ab
		#check address book is available
		res=`ls | grep $ab | wc -w`
		
		if [ $res -gt 0 ]
		then
				cat $ab
		else
				echo "Error: File does not exist"
		fi
}

insert()
{
		echo "Enter address book name"
		read ab
		#check address book is available
		res=`ls | grep $ab | wc -w`
		
		if [ $res -gt 0 ]
		then
				echo "Enter phone"
				read phone
				
				#check email present or not
				len=`cat $ab | grep $phone | wc -w`
				if [ $len -gt 0 ]
				then
						echo "Error: number already exists"
				else
						echo "Enter First name, Last name, email"
						read fname lname email
						
						record=`echo $fname $lname $phone $email`
						echo $record >> $ab
						echo "Record inserted"
				fi
				
		else
				echo "Error: File does not exist"
		fi
}

modify()
{
		echo "Enter address book name"
		read ab
		#check address book is available
		res=`ls | grep $ab | wc -w`
		
		if [ $res -gt 0 ]
		then
				echo "Enter phone"
				read phone
				
				#check email present or not
				len=`cat $ab | grep $phone | wc -w`
				if [ $len -gt 0 ]
				then
						echo "Enter modified first name, last name, email"
						read fname lname email
						new=`echo $fname $lname $phone $email`
						old=`cat $ab | grep $phone`
						
						echo "Old Record: $old"
						echo "New Record: $new"
						
						sed -i s/"$old"/"$new"/g $ab
						
						echo "Record Modified!"
				else
						echo "Error: number does not exist!"
				fi
				
		else
				echo "Error: File does not exist"
		fi
}

delete()
{
		echo "Enter address book name"
		read ab
		#check address book is available
		res=`ls | grep $ab | wc -w`
		
		if [ $res -gt 0 ]
		then
				echo "Enter phone"
				read phone
				
				#check number present or not
				len=`cat $ab | grep $phone | wc -w`
				if [ $len -gt 0 ]
				then
						old=`cat $ab | grep $phone`

						sed -i s/"$old"//g $ab
						sed -i /^$/d $ab
						echo "Record Deleted!"
				else
						echo "Error: number does not exist!"
				fi
				
		else
				echo "Error: File does not exist"
		fi
}

while [ true ]
do
		echo "*********MENU************"
		echo "1. Create"
		echo "2. Display"
		echo "3. Insert record"
		echo "4. Modify record"
		echo "5. Delete record"
		echo "7. Exit"
		
		echo "Enter Choice"
		read choice
		
		case $choice in
			1) create ;;
			
			2) display ;;
			
			3) insert ;;
			
			4) modify ;;

			5) delete ;;
			
			7) exit ;;
			
			*) echo "Wrong Choice!" ;;
		esac
done

			
