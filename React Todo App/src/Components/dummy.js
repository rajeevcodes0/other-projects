let audio = new Audio(
  "https://www.soundhelix.com/examples/mp3/SoundHelix-Song-1.mp3"
);

let button = document.getElementsByClassName("searchBtn pin-search-btn district-search")[0];

let text = document.getElementsByTagName("body")[0];


setInterval(()=>{
    if (text.innerText.toLowerCase().includes("aiims") || text.innerText.toLowerCase().includes("force") || text.innerText.toLowerCase().includes("railway")) {
        audio.play();
      }
      button.click();
},5000)