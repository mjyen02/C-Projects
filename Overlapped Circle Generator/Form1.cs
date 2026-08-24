namespace ECE4318_Final_Q2
{
    public partial class Form1 : Form
    {
        private Color circleColor = Color.Black;
        private int iterations = 18;
        private int radius = 40;
        private int centerX = 100;
        private int centerY = 100;

        public Form1()
        {
            Text = "Student Michael Yen's Beautiful Circles";
            Size = new Size(600, 600);
            FormBorderStyle = FormBorderStyle.FixedDialog;
            MaximizeBox = false;

            // Create drawing panel
            var drawPanel = new Panel
            {
                Location = new Point(0, 0),
                Size = new Size(600, 500),
                BorderStyle = BorderStyle.FixedSingle
            };
            drawPanel.Paint += DrawPanel_Paint;
            Controls.Add(drawPanel);

            // Create control panel
            var controlPanel = new Panel
            {
                Location = new Point(0, 500),
                Size = new Size(600, 100)
            };
            Controls.Add(controlPanel);

            // Create color selection combo box
            var colorLabel = new Label
            {
                Text = "Color:",
                Location = new Point(10, 10),
                AutoSize = true
            };
            controlPanel.Controls.Add(colorLabel);

            var colorComboBox = new ComboBox
            {
                Location = new Point(70, 10),
                Size = new Size(100, 20),
                DropDownStyle = ComboBoxStyle.DropDownList
            };
            colorComboBox.Items.AddRange(new string[] { "Black", "Green", "Red", "Blue" });
            colorComboBox.SelectedIndex = 0;
            colorComboBox.SelectedIndexChanged += (sender, e) =>
            {
                switch (colorComboBox.SelectedItem.ToString())
                {
                    case "Black":
                        circleColor = Color.Black;
                        break;
                    case "Green":
                        circleColor = Color.Green;
                        break;
                    case "Red":
                        circleColor = Color.Red;
                        break;
                    case "Blue":
                        circleColor = Color.Blue;
                        break;
                }
                drawPanel.Invalidate();
            };
            controlPanel.Controls.Add(colorComboBox);

            // Create iterations input field
            var iterationsLabel = new Label
            {
                Text = "Iterations:",
                Location = new Point(200, 10),
                AutoSize = true
            };
            controlPanel.Controls.Add(iterationsLabel);

            var iterationsField = new TextBox
            {
                Location = new Point(280, 10),
                Size = new Size(50, 20),
                Text = iterations.ToString()
            };
            controlPanel.Controls.Add(iterationsField);

            // Create update button
            var updateButton = new Button
            {
                Text = "Update",
                Location = new Point(350, 10),
                Size = new Size(80, 20)
            };
            updateButton.Click += (sender, e) =>
            {
                if (int.TryParse(iterationsField.Text, out int value))
                {
                    iterations = value;
                }
                else
                {
                    iterations = 18; // Default
                }
                drawPanel.Invalidate();
            };
            controlPanel.Controls.Add(updateButton);
        }

        private void DrawPanel_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            g.Clear(Color.White);

            using (Pen pen = new Pen(circleColor))
            {
                double theta = 0;
                int diameter = 2 * radius;

                for (int i = 0; i < iterations; ++i)
                {
                    int rx = (int)(centerX + radius * Math.Cos(theta)) - radius;
                    int ry = (int)(centerY + radius * Math.Sin(theta)) - radius;
                    g.DrawEllipse(pen, rx, ry, diameter, diameter);
                    theta += (2 * Math.PI / iterations);
                }
            }
        }
    }
}