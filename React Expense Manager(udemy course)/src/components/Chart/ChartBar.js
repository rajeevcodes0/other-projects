import React from "react";

import "./ChartBar.css";

const ChartBar = (props) => {
  let barFillHeight = "0%";
  if (props.maxValue) {
    barFillHeight = Math.round((props.value / props.maxValue) * 100) + "%";
  }
  console.log("barfillheight",barFillHeight);

  console.log("inside chartbar.js");
  return (
    <div className="chart-bar">
      <div className="chart-bar__inner">
        <div
          className="chart-bar__fill"
          style={{ height: barFillHeight}}
        ></div>
      </div>
      <div className="chart-bar__label">{props.label}</div>
    </div>
  );
};

export default ChartBar;
