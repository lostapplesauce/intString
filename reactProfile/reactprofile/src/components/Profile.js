import React from 'react';
import '../stylesheets/Profile.css'
import WindowTracker from './WindowTracker';

export default function Proifle() {
   
    
    return (
        <div className="profile--container">
            <h2 className="profile--title">About Me</h2>
            <p className="profile--description">
                <strong>Currenlty I am residing in Scotland and trying to get a working visa.</strong>
                <hr/>
                Enjoy being able to travel around and see all this beautiful planet offers.
                On top of traveling the opportunity to eat in various countries is amazing! 
                Love trying various cuisines and finding new dishes. During my free time, when at home, 
                been working on myself by improving programming skills with lessons online 
                and practice. 
                <br />
                Have a good amount of expierence working within a team. Through out my life I 
                have played variout sports from football to American football. Having also served
                in the military instilled, initially, the skillset to work witin a team at work.
                When a groupd of peope are working in sync and getting things accomplished it 
                creates an undescribable joy within myself. Teamwork makes the dream work.
                <br />
                When I have time I enjoying diving into art and getting the creative juices flowing.
                The moment when something of my imagination goes on to the page and looks remotely
                close is always an accomplishment, I am not the greatest artist but still find joy in it.
                Doing frontend web development work feels like an art project to me, being able to add
                components and make them come alive.                 
            </p>
            
            <WindowTracker />
        </div>
    )
}