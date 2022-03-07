let button = document.getElementById("spendAmount");


chrome.storage.sync.get(['total',"limit"],function(budget){
    document.getElementById("total").innerText=`${budget.total?parseInt(budget.total):0}`;
    document.getElementById("limit").innerText=budget.limit?budget.limit:"Not Set";

})



button.addEventListener("click",function(){

    chrome.storage.sync.get("total",function(budget){
        var newTotal = 0;
        if(budget.total){
            newTotal+=parseInt(budget.total);
        }

        chrome.storage.sync.get("limit",function(budget){
            if(newTotal>parseInt(budget.limit)){
                //create the notification object
                var notifOptions = {
                    type:"basic",
                    iconUrl:"icon48.png",
                    title:"Limit Reached",
                    message:"Oh no, you have reached the limit"
                }
                console.log(chrome.notifications);
                chrome.notifications.create(`${Math.random()}`,notifOptions);
            }
        });

        let amount = document.getElementById("amount").value;
        if(amount){
            newTotal += parseInt(amount);   
        }

        chrome.storage.sync.set({"total":newTotal});
        document.getElementById("total").innerText=`${newTotal}`;

        document.getElementById("amount").value="";
    });

})