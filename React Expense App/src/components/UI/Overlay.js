//importing libraries
import React from "react";
import ReactDOM from 'react-dom';

//importing stylesheet
import classes from './Overlay.module.css';

const Overlay = (props) => {
    console.log("overlay props", props);
    console.log(ReactDOM.createPortal);
    return ReactDOM.createPortal(<div className={classes.overlay} onClick={props.onClick}></div>,document.getElementById("overlay"))
};

export default Overlay;
