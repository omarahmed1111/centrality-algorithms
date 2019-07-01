const electron = require('electron');
const express = require('express');
const path = require('path');
const fs = require('fs');

//input.txt + degree.txt + closeness.txt + betweenness.txt -> computation.txt
//---------------------------------------------------------------------------------

const input = fs.readFileSync('input.txt', 'utf-8').split(/\r?\n/);
const degree = fs.readFileSync('degree.txt', 'utf-8').split(/\r?\n/);
const closeness = fs.readFileSync('closeness.txt', 'utf-8').split(/\r?\n/);
const betweenness = fs.readFileSync('betweenness.txt', 'utf-8').split(/\r?\n/);

let links = [];
let nodes = [];
let maxDegree = -1,
  maxBetweenness = -1;

for (let index = 1; index <= parseInt(input[0].split(' ')[1]); index++) {
  let temp = {
    source: input[index].split(' ')[0],
    target: input[index].split(' ')[1]
  };
  links.push(temp);
}

for (let index = 0; index < parseInt(input[0].split(' ')[0]); index++) {
  let temp = {
    id: index.toString(),
    centrality: {
      degree: parseFloat(degree[index]),
      closeness: parseFloat(closeness[index]),
      betweenness: parseFloat(betweenness[index])
    }
  };
  nodes.push(temp);
  maxDegree = Math.max(maxDegree, parseFloat(degree[index]));
  maxBetweenness = Math.max(maxBetweenness, parseFloat(betweenness[index]));
}

fs.writeFileSync('./assets/computation.json', JSON.stringify({ nodes, links }));

//---------------------------------------------------------------------------------

const ex_app = express();
ex_app.use(express.static(path.join(__dirname, 'assets')));

ex_app.set('view engine', 'ejs');

ex_app.get('/', (req, res) => {
  res.render('index.ejs', { maxDegree, maxBetweenness });
});

const PORT = process.env.PORT || 3000;

ex_app.listen(PORT, () => console.log(`Server Running On Port ${PORT}`));

const { app, BrowserWindow, Menu } = electron;

let mainWindow;

//! Fix proxy issue which delays sending the request to Express
app.commandLine.appendSwitch('no-proxy-server');

// Listen for app to be ready
app.on('ready', function() {
  // Create new window and start maximized
  mainWindow = new BrowserWindow({ show: false });
  mainWindow.maximize();
  mainWindow.show();

  // Load mainWindow
  mainWindow.loadURL('http://localhost:3000');

  // Quit app when closed
  mainWindow.on('closed', function() {
    app.quit();
  });

  // Build menu from template
  const mainMenu = Menu.buildFromTemplate(mainMenuTemplate);
  // Insert menu
  Menu.setApplicationMenu(mainMenu);
});

// Create menu template
const mainMenuTemplate = [
  {
    label: 'View',
    submenu: [
      { role: 'resetzoom' },
      { role: 'zoomin' },
      { role: 'zoomout' },
      { role: 'togglefullscreen' }
    ]
  },
  {
    label: 'Reset',
    role: 'reload'
  }
];

mainMenuTemplate.push({
  label: 'Developer Tools',
  submenu: [
    {
      label: 'Toggle DevTools',
      accelerator: process.platform == 'darwin' ? 'Command+I' : 'Ctrl+I',
      click(item, focusedWindow) {
        focusedWindow.toggleDevTools();
      }
    }
  ]
});
