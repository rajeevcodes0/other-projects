var elementsData=[];

fetch("./data.json")
    .then((response) => {return response.json() })
    .then((data) => { 
        for(let i=0;i<data.length;i++){
            elementsData.push(data[i]);
        }
    })
    .then(() => {
        console.log("elements data imported");
    });