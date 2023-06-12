package edu.ucc.arqSoft.service.model;

import java.util.Set;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.EnumType;
import javax.persistence.Enumerated;
import javax.persistence.FetchType;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.OneToMany;
import javax.persistence.Table;
import javax.validation.constraints.NotNull;
import javax.validation.constraints.Size;

import org.hibernate.annotations.Proxy;

import edu.ucc.arqSoft.service.common.model.GenericObject;

@Entity
@Table(name = "Sensor")
@Proxy(lazy = false)
public class Sensor extends GenericObject{

	/*@Enumerated(value = EnumType.ORDINAL)
	@Column(name = "Location")
	private Location location;*/

	@NotNull
	@Column(name = "Status")
	private Status status;

	@NotNull
	@ManyToOne(fetch = FetchType.EAGER)
	@JoinColumn(name="Location_ID")
	private Location location;

	public Location getLocation() {
		return location;
	}

	public void setLocation(Location location) {
		this.location = location;
	}

	public Status getStatus() {
		return status;
	}

	public void setStatus(Status status) {
		this.status = status;
	}
	
	@OneToMany(mappedBy="sensor", fetch = FetchType.LAZY)
	private Set<Register> registers;

 	public Set<Register> getRegisters() {
	 	return registers;
	 }

 	public void setRegister(Set<Register> registers) {
	 	this.registers = registers;
 	}

}