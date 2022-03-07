var contextMenuItem = {
  id: "spendMoney",
  title: "SpendMoney",
  contexts: ["selection"],
};

chrome.contextMenus.create(contextMenuItem);

function isInt(value) {
  return (
    !isNaN(value) &&
    parseInt(Number(value)) == value &&
    !isNaN(parseInt(value, 10))
  );
}

chrome.contextMenus.onClicked.addListener(function (clickedData) {
  if ((clickedData.menuItemId = "spendMoney" && clickedData.selectionText)) {

      if(isInt(clickedData.selectionText)){

          chrome.storage.sync.get(['total','limit'],function(budget){

              var newTotal = 0;
              if(budget.total){
                  newTotal+=parseInt(budget.total);
              }

              newTotal +=parseInt(clickedData.selectionText);
              chrome.storage.sync.set({"total":newTotal},function(){

                  if(newTotal>=budget.limit){
                    var notifOptions = {
                        type:"basic",
                        iconUrl:"icon48.png",
                        title:"Limit Reached",
                        message:"Oh no, you have reached the limit"
                    }
                    chrome.notifications.create(`${Math.random()}`,notifOptions);
                  }

              })
          })
      }
  }
});

chrome.storage.onChanged.addListener(function(changes,storageName){
    chrome.browserAction.setBadgeText({"text":changes.total.newValue.toString()});
})