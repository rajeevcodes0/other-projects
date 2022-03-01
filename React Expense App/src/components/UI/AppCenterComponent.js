//importing libraries
import React from 'react';

//importing stylesheets
import classes from './AppCenterComponent.module.css';

//this component centers the container of the App,
//without this I was having trouble with overlay, 
//the overlay was getting to the center because of flex of the body.
//so we needed to remove flex from body, and still center the app

const AppCenterComponent = (props)=>{
    return(
        <div className={classes["app-flex-wrapper"]}>
            {props.children}
        </div>
    )
}

export default AppCenterComponent;
