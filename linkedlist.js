let node = {
	data: '',
	next: null
}




function printOptions() {
	console.log('1.add a node to the list\n')
	console.log('2.remove a node from the list\n')
	console.log('3.insert a node to the list\n')
	console.log('4.print the list \n')
	console.log('5.quit')
}


let option = 0;

while (option != 5) {
printOptions()
option = prompt();

if(option > 0 && option < 5){
	switch(option){
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		break;}}
}
