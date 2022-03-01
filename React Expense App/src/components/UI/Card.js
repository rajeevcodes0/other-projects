//importing libraries
import React from 'react';

//importing stylesheets
import classes from "./Card.module.css";

const Card = (props)=>{
    return(
        <div className={`${props.className} ${classes.card}`}>
            {props.children}
        </div>
    );
}

export default Card;