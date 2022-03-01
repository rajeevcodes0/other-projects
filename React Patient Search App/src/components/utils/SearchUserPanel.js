import React from "react";
import Button from "../ui/Button";
import Input from "../ui/Input";
import { useContext, useState } from "react";
import AppManager from "../../store/app-manager";
import ShowResult from "./ShowResult";

import classes from "./SearchUserPanel.module.css";

const SearchUserPanel = () => {
  const appManagerContext = useContext(AppManager);

  const [id, setId] = useState("");

  const idOnChangeHandler = (e) => {
    setId(e.target.value);
  };

  let isShowingSearchedData = false;
  if (appManagerContext.receivedSearchedData) {
    isShowingSearchedData = true;
  } else {
    isShowingSearchedData = false;
  }
  const onSubmitHandler = (e) => {
    e.preventDefault();
    appManagerContext.onSearchHandler(parseInt(e.target[0].value));
    setId("");
  };
  return (
    <div className={classes["search-user-panel-container-center-div"]}>
      <div className={classes["search-user-panel-container"]}>
        <form onSubmit={onSubmitHandler}>
          <Input
            type="text"
            name="Enter ID"
            id="search-bar"
            onChange={idOnChangeHandler}
            value={id}
            className={classes['input-container']}
          ></Input>
          {!appManagerContext.receivedSearchData && (
            <Button name="Search" type="submit" disabled={id.trim().length>0?false:true} className={id.trim().length>0?classes['active']:classes['inactive']}></Button>
          )}
        </form>
        {isShowingSearchedData && <ShowResult />}
      </div>
    </div>
  );
};

export default SearchUserPanel;
