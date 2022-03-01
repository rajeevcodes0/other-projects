////importing libraries
import React from "react";
import ReactDOM from "react-dom";

//importing hooks
import { useContext } from "react";

//importing app context
import AppData from "../../store/app-data";

//importing stylesheet
import classes from "./Modal.module.css";

const Modal = (props) => {
  const appData = useContext(AppData);
  let selectedThemeClass ="";
  if(appData.selectedTheme==="dark"){
    selectedThemeClass="dark-mode-theme";
  }else if(appData.selectedTheme==="light"){
    selectedThemeClass="light-mode-theme"
  }else if(appData.selectedTheme==="violet"){
    selectedThemeClass="violet-mode-theme"
  }
  return ReactDOM.createPortal(
    <div className={`${classes[selectedThemeClass]} ${classes.modal}`}>{props.children}</div>,
    document.getElementById("modal")
  );
};

export default Modal;
