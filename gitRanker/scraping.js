const axios = require('axios');
const cheerio = require('cheerio');
const fs = require('fs');

const data = require('../Data/results.json');

const commitLogs = [];

const getAuthor = data => {
    for (let registration of data) {
        let Team = {
            teamName: '',
            github: '',
            email: '',
            commits: 0
        };
        Team.teamName = registration['Team Name'];
        let handles = [
            {
                id: registration.git1,
                email: registration['Email Id of 1st member']
            },
            {
                id: registration.git2,
                email: registration['Email Id of 2nd member']
            },
            {
                id: registration.git3,
                email: registration['Email Id of 3rd member']
            },
            {
                id: registration.git4,
                email: registration['Email Id of 4th member']
            },
            {
                id: registration.git5,
                email: registration['Email Id of 5th member']
            }
        ];
        let count = 0;
        //emails = emails.filter(email => email.length > 0);
        handles = handles.filter(handle => handle.id.length > 0);

        for (let handle of handles) {
            // console.log(Team);
            getData = async () => {
                const response = await axios.get(handle.id);
                const html = response.data;
                const $ = cheerio.load(html);
                let element = $('.f4.text-normal.mb-2').text();
                let name = $(
                    '.p-name.vcard-fullname.d-block.overflow-hidden'
                ).text();
                let numbers = element.match(/\d+/g).map(Number);
                Team.commits = numbers[0];
                Team.email = handle.email;
                Team.github = handle.id;
                //console.log(Team);
                commitLogs.push(Team);
                await fs.appendFileSync(
                    'data.json',
                    JSON.stringify(Team, null, 2) + ',',
                    'utf-8'
                );
            };
            getData();
        }
    }
};
getAuthor(data);
