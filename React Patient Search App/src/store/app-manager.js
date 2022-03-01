import React from "react";

import { useState, useEffect } from "react";

const AppManager = React.createContext({
  isUserLoggedIn: false,
  logInHandler: () => {},
  logOutHandler: () => {},

  receivedSearchedData: {},
  hideSearchedData: () => {},
  showSearchedData: () => {},

  admin: {},
  allPatients: [],
  addPatientHandler: () => {},
  onSearchHandler: () => {},

  selectedPanel: "",
  onPanelChangeHandler: () => {},

  isShowingDialog: false,
  hideDialog: () => {},
  showDialog: () => {},

  newlyGeneratedID:""
});

export const AppManagerProvider = (props) => {

  const [isUserLoggedIn, setIsUserLoggedIn] = useState(false);

  const [isShowingDialog, setIsShowingDialog] = useState(false);

  useEffect(()=>{
      if((localStorage.getItem("isLoggedIn")==="true")){
          setIsUserLoggedIn(true);
      }
  },[])

  const showDialog = () => {
    if (isShowingDialog) {
        console.log("already showing dialogue");
      return;
    }
    setIsShowingDialog(true);
  };

  const hideDialog = () => {
    setIsShowingDialog(false);
  };

  //authData is an object that contains the entered data of the user trying to log in
  const logInHandler = async (authData) => {
     
    const response = await fetch(
      `https://genxtutorial.com/api/login/index.php?username=${authData.username} && password=${authData.password}`
    );

    const data = await response.json();

    // console.log(data);

    if (data.status) {
      setIsUserLoggedIn(true);
      localStorage.setItem("isLoggedIn","true");
      hideDialog(); //so we don't see dialogues from other sessions
      return true;
    } else {
      showDialog();
      return false;
    }
  };

  const logOutHandler = () => {
    localStorage.removeItem("isLoggedIn");
    setIsUserLoggedIn(false);
    hideDialog();
    setNewlyGeneratedID("");
  };

  const [receivedSearchedData, setReceivedSearchedData] = useState("");

  const hideSearchedData = () => {
    setReceivedSearchedData({});
  };

  const showSearchedData = (data) => {
    setReceivedSearchedData(data);
  };

  const [newlyGeneratedID, setNewlyGeneratedID] = useState("");

  const addPatientHandler = async (newPatientData) => {
    // console.log("inside add patient", newPatientData);
    const response = await fetch(
      `https://genxtutorial.com/api/add/index.php?name=${newPatientData.name}&&age=${newPatientData.age}&&address=${newPatientData.address}&&gender=${newPatientData.gender} && lastVisit=${newPatientData.lastVisit}`
    );

    // console.log(response);

    const data = await response.json();

    // console.log(obj);
    // console.log(newPatientData);
    // setAllPatients((prevState) => {
    //   return [...prevState, newPatientData];
    // });
    // console.log("user added");
    setNewlyGeneratedID(data.id);
    showDialog();
  };

  const onSearchHandler = async (id) => {
    // console.log("onSearchHandler called");
    // console.log("searching for the id", id);
    // let result = allPatients.filter((patient) => {
    //   // console.log("searching in patient", patient);
    //   return patient.id == id;
    // });
    // console.log("searching in");
    // console.log(allPatients);
    // console.log("searching now")
    // console.log(result);

    const response = await fetch(`https://genxtutorial.com/api/search/index.php?id=${id}`);

    const data = await response.json();
    

    // console.log("after search",data);

    
    //it was all capital when received from the server
    //but the dummy of the app, was using lowercases.
    


    if (data.status) {

    const changedNameData = {
        id:data.user.ID,
        name:data.user.NAME,
        age:data.user.AGE,
        address:data.user.ADDRESS,
        gender:data.user.GENDER,
        lastVisit:data.user.LASTVISIT
    }
      
      setReceivedSearchedData(changedNameData);
    } else {
      setReceivedSearchedData("");
    }
  };

  const [selectedPanel, setSelectedPanel] = useState("add");

  const onPanelChangeHandler = (panelName) => {
    setSelectedPanel(panelName);
  };

  return (
    <AppManager.Provider
      value={{
        isUserLoggedIn: isUserLoggedIn,
        logInHandler: logInHandler,
        logOutHandler: logOutHandler,

        receivedSearchedData: receivedSearchedData,
        showSearchedData: showSearchedData,
        hideSearchedData: hideSearchedData,

        addPatientHandler: addPatientHandler,
        onSearchHandler: onSearchHandler,

        selectedPanel: selectedPanel,
        onPanelChangeHandler: onPanelChangeHandler,


        isShowingDialog: isShowingDialog,
        showDialog: showDialog,
        hideDialog: hideDialog,

        newlyGeneratedID:newlyGeneratedID
      }}
    >
      {props.children}
    </AppManager.Provider>
  );
};

export default AppManager;
