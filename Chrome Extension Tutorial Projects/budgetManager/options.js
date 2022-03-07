let saveLimitButton = document.getElementById("saveLimit");

let resetTotalButton = document.getElementById("resetTotal");

chrome.storage.sync.get("limit",function(budget){
    document.getElementById("limit").value = budget.limit?budget.limit:"";
})

saveLimitButton.addEventListener("click",function(){
   var limit = document.getElementById("limit").value;
   if(limit){
       chrome.storage.sync.set({"limit":limit},function(){
           close();
       });
   }
});

resetTotalButton.addEventListener("click",function(){
    chrome.storage.sync.set({"total":0},function(){
        var notifOptions={
            type:"basic",
            iconUrl:"icon48.png",
            title:"Resetting",
            message:"Your total has been set to zero"
        }
        chrome.notifications.create(`${Math.random()}`,notifOptions);
        close();
    });
});