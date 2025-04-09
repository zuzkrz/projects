namespace JaProjektGUI
{
    partial class EmbossingFilter
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            SourceLabel = new Label();
            ComboLabel = new Label();
            NoThreadsLabel = new Label();
            ChooiceDll = new ComboBox();
            NoThreadsSelected = new NumericUpDown();
            ImageSelectButton = new Button();
            FilterButton = new Button();
            ResultImage = new PictureBox();
            ResultLabel = new Label();
            Time1Label = new Label();
            Time2Label = new Label();
            SaveButton = new Button();
            SourceImage = new PictureBox();
            ((System.ComponentModel.ISupportInitialize)SourceImage).BeginInit();
            ((System.ComponentModel.ISupportInitialize)NoThreadsSelected).BeginInit();
            ((System.ComponentModel.ISupportInitialize)ResultImage).BeginInit();
            SuspendLayout();
            // 
            // SourceImage
            // 
            SourceImage.BackColor = SystemColors.ScrollBar;
            SourceImage.Location = new Point(39, 12);
            SourceImage.Name = "SourceImage";
            SourceImage.Size = new Size(423, 273);
            SourceImage.SizeMode = PictureBoxSizeMode.StretchImage;
            SourceImage.TabIndex = 0;
            SourceImage.TabStop = false;
            // 
            // SourceLabel
            // 
            SourceLabel.AutoSize = true;
            SourceLabel.Font = new Font("Sitka Banner", 12F, FontStyle.Regular, GraphicsUnit.Point, 238);
            SourceLabel.Location = new Point(192, 288);
            SourceLabel.Name = "SourceLabel";
            SourceLabel.Size = new Size(93, 23);
            SourceLabel.TabIndex = 1;
            SourceLabel.Text = "Source Image";
            // 
            // ComboLabel
            // 
            ComboLabel.AutoSize = true;
            ComboLabel.Location = new Point(76, 320);
            ComboLabel.Name = "ComboLabel";
            ComboLabel.Size = new Size(63, 15);
            ComboLabel.TabIndex = 2;
            ComboLabel.Text = "Choose dll";
            // 
            // NoThreadsLabel
            // 
            NoThreadsLabel.AutoSize = true;
            NoThreadsLabel.Location = new Point(353, 320);
            NoThreadsLabel.Name = "NoThreadsLabel";
            NoThreadsLabel.Size = new Size(123, 15);
            NoThreadsLabel.TabIndex = 3;
            NoThreadsLabel.Text = "Choose no. of threads";
            // 
            // ChooiceDll
            // 
            ChooiceDll.FormattingEnabled = true;
            ChooiceDll.Items.AddRange(new object[] { "ASM", "C" });
            ChooiceDll.Location = new Point(76, 338);
            ChooiceDll.Name = "ChooiceDll";
            ChooiceDll.Size = new Size(121, 23);
            ChooiceDll.TabIndex = 4;
            ChooiceDll.Text = "ASM";
            // 
            // NoThreadsSelected
            // 
            NoThreadsSelected.Location = new Point(353, 338);
            NoThreadsSelected.Minimum = new decimal(new int[] { 1, 0, 0, 0 });
            NoThreadsSelected.Name = "NoThreadsSelected";
            NoThreadsSelected.Size = new Size(120, 23);
            NoThreadsSelected.TabIndex = 5;
            NoThreadsSelected.Value = new decimal(new int[] { 1, 0, 0, 0 });
            // 
            // ImageSelectButton
            // 
            ImageSelectButton.Location = new Point(82, 430);
            ImageSelectButton.Name = "ImageSelectButton";
            ImageSelectButton.Size = new Size(203, 82);
            ImageSelectButton.TabIndex = 6;
            ImageSelectButton.Text = "Select Image";
            ImageSelectButton.UseVisualStyleBackColor = true;
            ImageSelectButton.Click += ImageSelectButton_Click;
            // 
            // FilterButton
            // 
            FilterButton.Location = new Point(319, 430);
            FilterButton.Name = "FilterButton";
            FilterButton.Size = new Size(203, 82);
            FilterButton.TabIndex = 7;
            FilterButton.Text = "Apply Filter";
            FilterButton.UseVisualStyleBackColor = true;
            FilterButton.Click += FilterButton_Click;
            // 
            // ResultImage
            // 
            ResultImage.BackColor = SystemColors.ScrollBar;
            ResultImage.Location = new Point(613, 12);
            ResultImage.Name = "ResultImage";
            ResultImage.Size = new Size(423, 273);
            ResultImage.SizeMode = PictureBoxSizeMode.StretchImage;
            ResultImage.TabIndex = 8;
            ResultImage.TabStop = false;
            // 
            // ResultLabel
            // 
            ResultLabel.AutoSize = true;
            ResultLabel.Font = new Font("Sitka Banner", 12F);
            ResultLabel.Location = new Point(790, 288);
            ResultLabel.Name = "ResultLabel";
            ResultLabel.Size = new Size(90, 23);
            ResultLabel.TabIndex = 9;
            ResultLabel.Text = "Result Image";
            // 
            // Time1Label
            // 
            Time1Label.AutoSize = true;
            Time1Label.Location = new Point(656, 346);
            Time1Label.Name = "Time1Label";
            Time1Label.Size = new Size(36, 15);
            Time1Label.TabIndex = 10;
            Time1Label.Text = "Time:";
            // 
            // Time2Label
            // 
            Time2Label.AutoSize = true;
            Time2Label.Location = new Point(698, 346);
            Time2Label.Name = "Time2Label";
            Time2Label.Size = new Size(0, 15);
            Time2Label.TabIndex = 11;
            // 
            // SaveButton
            // 
            SaveButton.Location = new Point(799, 430);
            SaveButton.Name = "SaveButton";
            SaveButton.Size = new Size(203, 82);
            SaveButton.TabIndex = 12;
            SaveButton.Text = "Save Result";
            SaveButton.UseVisualStyleBackColor = true;
            SaveButton.Click += SaveButton_Click;
            // 
            // EmbossingFilter
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1079, 564);
            Controls.Add(SaveButton);
            Controls.Add(Time2Label);
            Controls.Add(Time1Label);
            Controls.Add(ResultLabel);
            Controls.Add(ResultImage);
            Controls.Add(FilterButton);
            Controls.Add(ImageSelectButton);
            Controls.Add(NoThreadsSelected);
            Controls.Add(ChooiceDll);
            Controls.Add(NoThreadsLabel);
            Controls.Add(ComboLabel);
            Controls.Add(SourceLabel);
            Controls.Add(SourceImage);
            Name = "EmbossingFilter";
            Text = "EmbossyFilter";
            ((System.ComponentModel.ISupportInitialize)SourceImage).EndInit();
            ((System.ComponentModel.ISupportInitialize)NoThreadsSelected).EndInit();
            ((System.ComponentModel.ISupportInitialize)ResultImage).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion
        private String sourcePath;
        private PictureBox ResultImage;
        private PictureBox SourceImage;
        private Label SourceLabel;
        private Label ResultLabel;
        private ComboBox ChooiceDll;
        private Label ComboLabel;
        private Button ImageSelectButton;
        private Button FilterButton;
        private NumericUpDown NoThreadsSelected;
        private Label NoThreadsLabel;
        private Label Time1Label;
        private Label Time2Label;
        private Button SaveButton;
    }
}
