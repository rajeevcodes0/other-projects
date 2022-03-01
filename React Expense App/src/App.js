//importing libraries
import React from "react";

//importing stylesheets
import classes from "./App.module.css";

//importing context
import AppData from "./store/app-data";

//importing hooks
import { useContext, useState } from "react";

//import UI components
import Card from "./components/UI/Card";
import Modal from "./components/UI/Modal";
import Container from "./components/Container/Container";
import Overlay from "./components/UI/Overlay";

//importing constituting components
import Header from "./components/Header/Header";
import Balance from "./components/Constituting/Balance";
import Footer from "./components/Footer/Footer";
import Overview from "./components/Constituting/Overview";
import ExpenseList from "./components/Constituting/ExpenseList";
import AddLogForm from "./components/Constituting/AddLogForm";
import Settings from "./components/Settings/Settings";
import AppCenterComponent from "./components/UI/AppCenterComponent";

const App = () => {
  console.log("rendering app component");
  const appData = useContext(AppData);
  const [showAddLogForm, setShowAddLogForm] = useState(false);
  const [showSettings, setShowSettings] = useState(false);

  const toggleAddLogFormHandler = () => {
    setShowAddLogForm((prevState) => {
      return !prevState;
    });
  };

  const toggleShowSettings = () => {
    setShowSettings((prevState) => {
      return !prevState;
    });
  };

  //selecting the body color depending on the theme
  let bodyColor = "";
  if (appData.selectedTheme === "dark") {
    bodyColor = "rgb(41, 40, 40)";
  } else if (appData.selectedTheme === "light") {
    bodyColor = "white";
  } else if (appData.selectedTheme === "violet") {
    bodyColor = "rgb(61, 45, 117)";
  }

  //changing the body color
  document.getElementsByTagName("body")[0].style.backgroundColor = bodyColor;

  let selectedThemeClass = "";
  if (appData.selectedTheme === "dark") {
    selectedThemeClass = "dark-mode-theme";
  } else if (appData.selectedTheme === "light") {
    selectedThemeClass = "light-mode-theme";
  } else if (appData.selectedTheme === "violet") {
    selectedThemeClass = "violet-mode-theme";
  }

  return (
    <AppCenterComponent>
      <Container>
        {showAddLogForm && (
          <React.Fragment>
            <Overlay onClick={toggleAddLogFormHandler} />
            <Modal>
              <AddLogForm
                onFormSubmission={toggleAddLogFormHandler}
              ></AddLogForm>
            </Modal>
          </React.Fragment>
        )}

        {showSettings && (
          <React.Fragment>
            <Overlay onClick={toggleShowSettings} />
            <Modal>
              <Settings onClose={toggleShowSettings} />
            </Modal>
          </React.Fragment>
        )}
        <Card className={classes[selectedThemeClass]}>
          <Header onSettingsButtonClick={toggleShowSettings} />
          <Balance onToggleAddLogForm={toggleAddLogFormHandler} />
          <Overview />
          <ExpenseList expenses={appData.expenseData.logArray} />
          <Footer />
        </Card>
      </Container>
    </AppCenterComponent>
  );
};

export default App;
