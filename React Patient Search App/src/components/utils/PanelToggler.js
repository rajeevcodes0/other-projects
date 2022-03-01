import React from "react";
import Button from "../ui/Button";

import AppManager from "../../store/app-manager";

import { useContext } from "react";

import classes from "./PanelToggler.module.css";

const PanelToggler = () => {
  const appManagerContext = useContext(AppManager);

  const onClickHandler = (e) => {
    appManagerContext.onPanelChangeHandler(e.target.dataset.id);
  };


  let selectedPanel = appManagerContext.selectedPanel;

  return (
    <div className={classes["panel-toggler-container"]}>
      <div className={classes["panel-toggler-button-container"]}>
        <Button
          type="button"
          disabled={false}
          name="Add"
          dataID="add"
          onClick={onClickHandler}
          className={selectedPanel==='add'?classes['active']:""}
        ></Button>

        <Button
          type="button"
          disabled={false}
          name="Search"
          dataID="search"
          onClick={onClickHandler}
          className={selectedPanel==='search'?classes['active']:""}
        ></Button>
      </div>
    </div>
  );
};

export default PanelToggler;
