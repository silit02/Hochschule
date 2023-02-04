const red = document.getElementById("red");
const yellow = document.getElementById("yellow");
const green = document.getElementById("green");

let currentLight = "red";
let previousLight = null;

setInterval(() => {
	if (currentLight === "red") {
		yellow.style.visibility = "visible";
		currentLight = "yellow";
		previousLight = "red";
	} else if (currentLight === "yellow" && previousLight === "red") {
		red.style.visibility = "hidden";
		yellow.style.visibility = "hidden";
		green.style.visibility = "visible";
		currentLight = "green";
		previousLight = "redyellow"
	} else if (currentLight === "green") {
		green.style.visibility = "hidden";
		yellow.style.visibility = "visible";
		currentLight = "yellow";
		previousLight = "green";
	} else {
		yellow.style.visibility = "hidden";
		red.style.visibility = "visible";
		currentLight = "red";
		previousLight = "yellow";
	}
}, 2000);
