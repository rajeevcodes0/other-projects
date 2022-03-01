import React from "react";

import "./Chart.css";

import ChartBar from "./ChartBar";

const Chart = (props) => {
  let allAmounts = props.dataPoints.map((dataPoint) => {
    return dataPoint.value;
  });
  let maxValue = Math.max(...allAmounts);
  return (
    <div className="chart">
      {props.dataPoints.map((dataPoint) => {
        return (
          <ChartBar
            key={dataPoint.label}
            value={dataPoint.value}
            maxValue={maxValue}
            label={dataPoint.label}
          />
        );
      })}
    </div>
  );
};

export default Chart;
