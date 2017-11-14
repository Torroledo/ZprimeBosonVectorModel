from math import exp

from math import tanh

class test:
	def value(self,index,in0,in1,in2,in3,in4,in5,in6):
		self.input0 = (in0 - 0.0183526)/3.46889
		self.input1 = (in1 - -0.00187054)/1.5593
		self.input2 = (in2 - -0.0202231)/2.16215
		self.input3 = (in3 - 0.0383211)/2.53588
		self.input4 = (in4 - 305.876)/169.167
		self.input5 = (in5 - 238.287)/181.995
		self.input6 = (in6 - 167.49)/129.515
		if index==0: return self.neuron0x7f9b5d923af0();
		return 0.
	def neuron0x7f9b5a75b980(self):
		return self.input0
	def neuron0x7f9b5d9e2790(self):
		return self.input1
	def neuron0x7f9b5a709c70(self):
		return self.input2
	def neuron0x7f9b5a7ebf40(self):
		return self.input3
	def neuron0x7f9b58a1ef20(self):
		return self.input4
	def neuron0x7f9b58a53530(self):
		return self.input5
	def neuron0x7f9b5d970840(self):
		return self.input6
	def neuron0x7f9b5d939db0(self):
		input = -7.05813
		input = input + self.synapse0x7f9b58a41eb0()
		input = input + self.synapse0x7f9b5d9ee6f0()
		input = input + self.synapse0x7f9b5d940ea0()
		input = input + self.synapse0x7f9b58ae87f0()
		input = input + self.synapse0x7f9b58a11900()
		input = input + self.synapse0x7f9b5a766400()
		input = input + self.synapse0x7f9b5d9e75c0()
		if input<-709. : return 0
		return ((1/(1+exp(-input)))*1)+0
	def neuron0x7f9b589fb780(self):
		input = 0.938848
		input = input + self.synapse0x7f9b5d9f2290()
		input = input + self.synapse0x7f9b5a732b20()
		input = input + self.synapse0x7f9b5d9f1d90()
		input = input + self.synapse0x7f9b58a48e50()
		input = input + self.synapse0x7f9b5d90a740()
		input = input + self.synapse0x7f9b58a22dc0()
		input = input + self.synapse0x7f9b58a4e340()
		if input<-709. : return 0
		return ((1/(1+exp(-input)))*1)+0
	def neuron0x7f9b58a25d60(self):
		input = -0.771725
		input = input + self.synapse0x7f9b5d9da690()
		input = input + self.synapse0x7f9b5d9db060()
		input = input + self.synapse0x7f9b58a35140()
		input = input + self.synapse0x7f9b5d9eeb70()
		input = input + self.synapse0x7f9b5d98d5d0()
		input = input + self.synapse0x7f9b5d962d40()
		input = input + self.synapse0x7f9b5a7e8ce0()
		if input<-709. : return 0
		return ((1/(1+exp(-input)))*1)+0
	def neuron0x7f9b5d9847b0(self):
		input = -11.0466
		input = input + self.synapse0x7f9b5d9eafa0()
		input = input + self.synapse0x7f9b5a7d63e0()
		input = input + self.synapse0x7f9b58a6e790()
		input = input + self.synapse0x7f9b5d9eca40()
		input = input + self.synapse0x7f9b5a744ec0()
		input = input + self.synapse0x7f9b5d9e1b40()
		input = input + self.synapse0x7f9b5a745c10()
		if input<-709. : return 0
		return ((1/(1+exp(-input)))*1)+0
	def neuron0x7f9b5d952250(self):
		input = 1.38103
		input = input + self.synapse0x7f9b5d9f1ba0()
		input = input + self.synapse0x7f9b58afaf20()
		input = input + self.synapse0x7f9b5d9f2f50()
		input = input + self.synapse0x7f9b5a701220()
		input = input + self.synapse0x7f9b5a723e80()
		input = input + self.synapse0x7f9b5a7c18f0()
		input = input + self.synapse0x7f9b5a7245a0()
		if input<-709. : return 0
		return ((1/(1+exp(-input)))*1)+0
	def neuron0x7f9b5d923af0(self):
		input = 1.8746
		input = input + self.synapse0x7f9b5a73c8c0()
		input = input + self.synapse0x7f9b58a1f180()
		input = input + self.synapse0x7f9b5d936000()
		input = input + self.synapse0x7f9b5a731910()
		input = input + self.synapse0x7f9b5a75c840()
		return (input*1)+0
	def synapse0x7f9b58a41eb0(self):
		return (self.neuron0x7f9b5a75b980()*2.83466)
	def synapse0x7f9b5d9ee6f0(self):
		return (self.neuron0x7f9b5d9e2790()*2.28374)
	def synapse0x7f9b5d940ea0(self):
		return (self.neuron0x7f9b5a709c70()*-3.16378)
	def synapse0x7f9b58ae87f0(self):
		return (self.neuron0x7f9b5a7ebf40()*0.00269477)
	def synapse0x7f9b58a11900(self):
		return (self.neuron0x7f9b58a1ef20()*1.05804)
	def synapse0x7f9b5a766400(self):
		return (self.neuron0x7f9b58a53530()*3.42551)
	def synapse0x7f9b5d9e75c0(self):
		return (self.neuron0x7f9b5d970840()*-1.32782)
	def synapse0x7f9b5d9f2290(self):
		return (self.neuron0x7f9b5a75b980()*-1.37877)
	def synapse0x7f9b5a732b20(self):
		return (self.neuron0x7f9b5d9e2790()*-0.478159)
	def synapse0x7f9b5d9f1d90(self):
		return (self.neuron0x7f9b5a709c70()*1.5079)
	def synapse0x7f9b58a48e50(self):
		return (self.neuron0x7f9b5a7ebf40()*0.0191)
	def synapse0x7f9b5d90a740(self):
		return (self.neuron0x7f9b58a1ef20()*0.245885)
	def synapse0x7f9b58a22dc0(self):
		return (self.neuron0x7f9b58a53530()*0.0206751)
	def synapse0x7f9b58a4e340(self):
		return (self.neuron0x7f9b5d970840()*-0.189606)
	def synapse0x7f9b5d9da690(self):
		return (self.neuron0x7f9b5a75b980()*1.01873)
	def synapse0x7f9b5d9db060(self):
		return (self.neuron0x7f9b5d9e2790()*0.493103)
	def synapse0x7f9b58a35140(self):
		return (self.neuron0x7f9b5a709c70()*-1.17857)
	def synapse0x7f9b5d9eeb70(self):
		return (self.neuron0x7f9b5a7ebf40()*-0.0069901)
	def synapse0x7f9b5d98d5d0(self):
		return (self.neuron0x7f9b58a1ef20()*0.0706982)
	def synapse0x7f9b5d962d40(self):
		return (self.neuron0x7f9b58a53530()*0.24712)
	def synapse0x7f9b5a7e8ce0(self):
		return (self.neuron0x7f9b5d970840()*0.0494613)
	def synapse0x7f9b5d9eafa0(self):
		return (self.neuron0x7f9b5a75b980()*-4.11947)
	def synapse0x7f9b5a7d63e0(self):
		return (self.neuron0x7f9b5d9e2790()*-4.02041)
	def synapse0x7f9b58a6e790(self):
		return (self.neuron0x7f9b5a709c70()*4.05796)
	def synapse0x7f9b5d9eca40(self):
		return (self.neuron0x7f9b5a7ebf40()*-0.362092)
	def synapse0x7f9b5a744ec0(self):
		return (self.neuron0x7f9b58a1ef20()*1.2977)
	def synapse0x7f9b5d9e1b40(self):
		return (self.neuron0x7f9b58a53530()*7.06033)
	def synapse0x7f9b5a745c10(self):
		return (self.neuron0x7f9b5d970840()*-4.28255)
	def synapse0x7f9b5d9f1ba0(self):
		return (self.neuron0x7f9b5a75b980()*0.388754)
	def synapse0x7f9b58afaf20(self):
		return (self.neuron0x7f9b5d9e2790()*-0.087711)
	def synapse0x7f9b5d9f2f50(self):
		return (self.neuron0x7f9b5a709c70()*0.365062)
	def synapse0x7f9b5a701220(self):
		return (self.neuron0x7f9b5a7ebf40()*0.0464112)
	def synapse0x7f9b5a723e80(self):
		return (self.neuron0x7f9b58a1ef20()*0.820636)
	def synapse0x7f9b5a7c18f0(self):
		return (self.neuron0x7f9b58a53530()*2.82218)
	def synapse0x7f9b5a7245a0(self):
		return (self.neuron0x7f9b5d970840()*-0.452985)
	def synapse0x7f9b5a73c8c0(self):
		return (self.neuron0x7f9b5d939db0()*0.958383)
	def synapse0x7f9b58a1f180(self):
		return (self.neuron0x7f9b589fb780()*-2.03965)
	def synapse0x7f9b5d936000(self):
		return (self.neuron0x7f9b58a25d60()*-2.45839)
	def synapse0x7f9b5a731910(self):
		return (self.neuron0x7f9b5d9847b0()*0.631339)
	def synapse0x7f9b5a75c840(self):
		return (self.neuron0x7f9b5d952250()*0.594978)
