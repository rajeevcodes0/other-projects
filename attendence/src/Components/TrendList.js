import React from "react";

import './TrendList.css';

import Trend from "./Trend";
const TrendList = (props) => {
  return (
    <ul className="trend-list">
      {props.data.map((dataElement) => {
        return <Trend id={dataElement.id} data={dataElement} />;
      })}
    </ul>
  );
};

export default TrendList;
