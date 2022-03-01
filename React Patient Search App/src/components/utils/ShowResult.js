import React from "react";
import AppManager from "../../store/app-manager";

import { useContext } from "react";

import classes from "./ShowResult.module.css";

const ShowResult = () => {
  const appManagerContext = useContext(AppManager);

  const data = appManagerContext.receivedSearchedData;

  // console.log("showing result for", data);
  //calculating date difference
  //first we convert 2021-10-21(yyyy-mm-dd) to [2021,10,21];
  let lastVisitArray = data.lastVisit.split("-");
  //then we create a date object for calculating difference
  let lastVisitObj = new Date(
    lastVisitArray[0],
    lastVisitArray[1] - 1,
    lastVisitArray[2]
  );
  //then we take the current date
  let currentDateObj = new Date();

  //then we calculate the difference using the formula mentioned below
  const differenceOfDays =
    (currentDateObj - lastVisitObj) / (1000 * 60 * 60 * 24);
  return (
    <div className={classes["show-result-container"]}>
      
      <div className={classes["data-container"]}>
        <p className={classes["data-name"]}>Number of days since last visit</p>
        <p className={classes["data"]}>
          {parseFloat(differenceOfDays).toFixed(0)}
        </p>
      </div>

      <div className={classes["data-container"]}>
        <p className={classes["data-name"]}>Last Visit On</p>
        <p className={classes["data"]}>{data.lastVisit}</p>
      </div>

      <div className={classes["data-container"]}>
        <p className={classes["data-name"]}>ID</p>
        <p className={classes["data"]}>{data.id}</p>
      </div>

      <div className={classes["data-container"]}>
        <p className={classes["data-name"]}>Name</p>
        <p className={classes["data"]}>{data.name}</p>
      </div>

      <div className={classes["data-container"]}>
        <p className={classes["data-name"]}>Age</p>
        <p className={classes["data"]}>{data.age}</p>
      </div>

      <div className={classes["data-container"]}>
        <p className={classes["data-name"]}>Gender</p>
        <p className={classes["data"]}>{data.gender}</p>
      </div>

      <div className={classes["data-container"]}>
        <p className={classes["data-name"]}>Address</p>
        <p className={classes["data"]}>{data.address}</p>
      </div>

      
    </div>
  );
};

export default ShowResult;
