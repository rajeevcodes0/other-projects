let inputElement = document.getElementById("name");


inputElement.addEventListener("keyup", ()=>{
    let heading = document.getElementsByTagName("h2")[0];
   heading.innerText = `Hello ${inputElement.value}`;
});
