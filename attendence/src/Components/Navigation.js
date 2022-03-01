import React from "react";

import './Navigation.css';

const Navigation = (props) => {
  return (
    <div className="navigation">
      <ul>
        <li>
          <button onClick={props.onSelectComponent}>Take Attendance</button>
        </li>
        <li>
          <button onClick={props.onSelectComponent}>Trend</button>
        </li>
      </ul>
    </div>
  );
};

export default Navigation;
