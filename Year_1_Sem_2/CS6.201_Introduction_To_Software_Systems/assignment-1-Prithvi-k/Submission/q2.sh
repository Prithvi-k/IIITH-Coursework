#!/bin/bash

CONTACT_BOOK="contacts.csv"

insert_contact()
{
	while getopts "f:l:n:o:" parameter
	do
		case $parameter in
			f) first_name="$OPTARG" ;;
			l) last_name="$OPTARG" ;;
			n) contact_number="$OPTARG" ;;
			o) company_name="$OPTARG" ;;
			*) exit 1 ;;
		esac
	done
	
	# check if first name already exists
	if grep -q "$first_name," "$CONTACT_BOOK"
	then
		echo "Unable to insert contact! First name already exists."
	else
		echo "$first_name,$last_name,$contact_number,$company_name" >> "$CONTACT_BOOK"
	fi

}

edit_contact()
{
	
	while getopts "k:f::l::n::o::" parameter
	do
		case $parameter in
			k) old_first_name="$OPTARG" ;;
			f) new_first_name="$OPTARG" ;;
			l) new_last_name="$OPTARG" ;;
			n) new_contact_number="$OPTARG" ;;
			o) new_company_name="$OPTARG" ;;
			*) exit 1 ;;
		esac
	done

	if grep -q "$old_first_name," "$CONTACT_BOOK"
	then
		if [ -z "$new_first_name" ]
		then
			new_first_name="$(grep "$old_first_name," "$CONTACT_BOOK" | cut -d ',' -f1)"
		fi
		if [ -z "$new_last_name" ]
		then
			new_last_name="$(grep "$old_first_name," "$CONTACT_BOOK" | cut -d ',' -f2)"
		fi
		if [ -z "$new_contact_number" ]
		then
			new_contact_number="$(grep "$old_first_name," "$CONTACT_BOOK" | cut -d ',' -f3)"
		fi

		if [ -z "$new_company_name" ]
		then
			new_company_name="$(grep "$old_first_name," "$CONTACT_BOOK" | cut -d ',' -f4)"
		fi

		sed -i "s/$old_first_name,\([^,]*\),\([^,]*\),\([^,]*\)$/$new_first_name,$new_last_name,$new_contact_number,$new_company_name/g" "$CONTACT_BOOK"
	fi
}

display_contact()
{
	sort_order=""
	while getopts "ad" parameter
	do
		case $parameter in
			a) sort_order="-k1,1" ;;
			d) sort_order="-k1,1r" ;;
			*) sort_order="" ;;
		esac
	done

	if [ -z "$sort_order" ]
	then
		cat $CONTACT_BOOK
	else
		head -n 1 "$CONTACT_BOOK"
		tail -n +2 "$CONTACT_BOOK" | sort -V -t ',' "$sort_order"
	fi
}

search_contact()
{
	while getopts "c:v:" parameter
	do
		case $parameter in
			c) column="$OPTARG" ;;
			v) value="$OPTARG" ;;
			*) exit 1 ;;
		esac
	done

	if [ "$column" == "fname" ]
	then
		column_number=1
	elif [ "$column" == "lname" ]
	then
		column_number=2
	elif [ "$column" == "mobile" ]
	then
		column_number=3
	elif [ "$column" == "office" ]
	then
		column_number=4
	fi

	count=$(awk -F ',' -v col="$column_number" -v val="$value" '$col == val' "$CONTACT_BOOK" | wc -l)
	if [ $count -gt 0 ]
	then
		awk -F ',' -v col="$column_number" -v val="$value" '$col == val' "$CONTACT_BOOK"
	else
		echo "No results found!"
	fi
}

delete_contact()
{
	while getopts "k:" parameter
	do
		case $parameter in
			k) first_name="$OPTARG" ;;
			*) ext 1 ;;
		esac
	done

	awk -F, -v first_name="$first_name" '$1 != first_name' "$CONTACT_BOOK" > tmp && mv tmp "$CONTACT_BOOK"
}

while getopts "C:" command
do
    case $command in
        C)
            case $OPTARG in
                insert) insert_contact "$@" ;;
				edit) edit_contact "$@" ;;
				display) display_contact "$@" ;;
				search) search_contact "$@" ;;
				delete) delete_contact "$@" ;;
				*) exit 1 ;;
            esac ;;
    esac
done