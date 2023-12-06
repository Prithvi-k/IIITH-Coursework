document.getElementById('hello-world-button').addEventListener("click", function () {
    alert("Prithvi Karthik");
});

document.getElementById('bold-button').addEventListener("click", function () {
    var elements = document.querySelectorAll("p, li");
    for (let index = 0; index < elements.length; index++) {
        elements[index].style.fontWeight = "bold";
    }
});

document.getElementById('unbold-button').addEventListener("click", function () {
    var elements = document.querySelectorAll("p, li");
    for (let index = 0; index < elements.length; index++) {
        elements[index].style.fontWeight = "normal";
    }
});

var images = ["images/cookie1.jpg", "images/cookie2.jpg", "images/cookie3.jpg"]
var imageNumber = 0;

document.getElementsByClassName('next-image-button')[0].addEventListener("click", function () {
    imageNumber = (imageNumber + 1) % images.length;
    document.getElementById('cookie-image').src = images[imageNumber];
});

var tracker = 0;
document.getElementById('dark-mode-switch').addEventListener('change', function () {
    if (tracker == 0) {
        document.body.style.backgroundColor = 'grey';
        tracker = 1;
    } else {
        document.body.style.backgroundColor = '#f2f2f2';
        tracker = 0;
    }
});

document.getElementById('new-joke').addEventListener('click', function () {
    fetch("https://official-joke-api.appspot.com/random_joke")
        .then(response => response.json())
        .then(data => {
            const joke = data;
            const setup = joke.setup;
            const punchline = joke.punchline;
            document.getElementById('joke').innerHTML = setup + "<br>" + punchline;
        })
        .catch(error => {
            console.log("error: " + error);
        })
});
