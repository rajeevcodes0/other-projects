//importing libraries
import React from 'react';

const Button = (props)=>{

    return <button data-itemID={props.itemID} className={props.className} onClick={props.onClick}>{props.title}</button>;
}

export default Button;