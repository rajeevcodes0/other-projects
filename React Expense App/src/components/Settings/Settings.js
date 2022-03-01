//importing libraries
import React from 'react';

//importing other components
import SelectTheme from './SelectTheme';

//importing stylesheets
import classes from './Settings.module.css';

const Settings = ()=>{
    return(
        <div className={classes["settings-container"]}>
            <SelectTheme/>
        </div>
    );
}

export default Settings;