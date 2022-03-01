import React from "react";

import AppManager from "../../store/app-manager";

import { useContext } from "react";

import classes from "./ErrorDialog.module.css";

const ErrorDialog = (props) => {
  const appManagerContext = useContext(AppManager);
  setTimeout(() => {
    appManagerContext.hideDialog();
  }, props.time);

  return (
    <div
      className={`${classes["dialog-container"]} ${
        props.type === "error" ? classes["error"] : classes["success"]
      }`}
    >
      <p>{props.message}</p>
      <button className={classes['close-dialog-button']} onClick={appManagerContext.hideDialog}>X</button>
    </div>
  );
};

export default ErrorDialog;
