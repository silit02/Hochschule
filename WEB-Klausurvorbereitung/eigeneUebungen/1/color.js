function changeColor() {
	if(document.getElementsByTagName("body")[0].style.backgroundColor == "red") {
		document.getElementsByTagName("body")[0].style.backgroundColor = "rgb(0,255,0)";
	} else {
		document.getElementsByTagName("body")[0].style.backgroundColor = "red";
	}
}

