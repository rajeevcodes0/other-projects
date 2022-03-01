import React from "react";

import "./Trend.css";

const Trend = (props) => {
  console.log("within trend", props);

  let allDays = props.data.attendance;
  let i=allDays.length-1;
  let lastSevenDays= [];
  while(i>=allDays.length-7){
      lastSevenDays.push(allDays[i]);
      i--;
  }
  lastSevenDays.reverse();
  return (
    <li className="trend">
      <p>{props.data.name}</p>
      <div className="trend-graph">
        <span className={lastSevenDays[0]?"present":"absent"}></span>
        <span className={lastSevenDays[1]?"present":"absent"}></span>
        <span className={lastSevenDays[2]?"present":"absent"}></span>
        <span className={lastSevenDays[3]?"present":"absent"}></span>
        <span className={lastSevenDays[4]?"present":"absent"}></span>
        <span className={lastSevenDays[5]?"present":"absent"}></span>
        <span className={lastSevenDays[6]?"present":"absent"}></span>
      </div>
    </li>
  );
};

export default Trend;
