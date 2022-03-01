const object = {
    name:"Rajeev Pandey",
    age: 25,
    address: "gorakhpur",
    gender: "M",
    lastVisit: Date.now()

}


let stringObj = JSON.stringify(object);

console.log(stringObj);

