package edu.ucc.arqSoft.service.service;

import java.sql.Timestamp;
import java.util.ArrayList;
import java.util.List;
import java.text.SimpleDateFormat; 
import java.util.Date;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import edu.ucc.arqSoft.service.dao.RegisterDao;
import edu.ucc.arqSoft.service.dao.SensorDao;
import edu.ucc.arqSoft.service.dto.RegisterRequestDto;
import edu.ucc.arqSoft.service.dto.RegisterResponseDto;
import edu.ucc.arqSoft.service.model.Register;
import edu.ucc.arqSoft.service.model.Sensor;

@Service
@Transactional
public class RegisterService {

	@Autowired
	private RegisterDao registerDao;
	
	@Autowired
	private SensorDao sensorDao;

	public RegisterResponseDto getRegisterById(Long id) {

		Register register = registerDao.load(id);

		RegisterResponseDto dto = new RegisterResponseDto();
		// verificar
		dto.setTemperature(register.getTemperature());
		dto.setPressure(register.getPressure());
		dto.setWind(register.getWind());
		dto.setTimestamp(register.getTimestamp());
		dto.setSensor(register.getSensor());
		dto.setId(id);
		
		return dto;

	}

	public RegisterResponseDto registrar(RegisterRequestDto dto) {
		
		

		Register register = new Register();
		register.setTemperature(dto.getTemperature());
		register.setPressure(dto.getPressure());
		register.setWind(dto.getWind());
		register.setTimestamp(dto.getTimestamp());
		register.setSensor(sensorDao.load(dto.getSensor_id())  );

		registerDao.insert(register);
		
		RegisterResponseDto response = new RegisterResponseDto();
		response.setTemperature(register.getTemperature());
		response.setPressure(register.getPressure());
		response.setWind(register.getWind());
		response.setTimestamp(register.getTimestamp());
		response.setSensor(register.getSensor());
		response.setId(register.getId());
		
		return response;
	}


	public List<RegisterResponseDto> getRegisters() {

		List<Register> registers = registerDao.getAll();
		
		
		List<RegisterResponseDto> dtos = new ArrayList<RegisterResponseDto>();
		
		RegisterResponseDto dto;
		for (Register register : registers) {
			dto = new RegisterResponseDto();
			dto.setTemperature(register.getTemperature());
			dto.setPressure(register.getPressure());
			dto.setWind(register.getWind());
			dto.setTimestamp(register.getTimestamp());
			dto.setSensor(register.getSensor());
			
			dtos.add(dto);
		}
		
		return dtos;
	}


	public List<RegisterResponseDto> getMeditions(Long id) {
		List<Register> registers = registerDao.getAll();
		
		List<RegisterResponseDto> dtos = new ArrayList<RegisterResponseDto>();
		
		RegisterResponseDto dto;

		//milisegundos en un día
		long dayInMili = 86400000;

		System.currentTimeMillis();
 
   		for (Register register : registers) { //revisar convertir string a local date time
			dto = new RegisterResponseDto();

			//diferencia de tiempo
			long deltaTime = System.currentTimeMillis() - register.getTimestamp().getTime();

			if (deltaTime <= dayInMili && deltaTime > 0 && register.getSensor().getId() == id) {
				
				dto.setTemperature(register.getTemperature());
				dto.setPressure(register.getPressure());
				dto.setWind(register.getWind());
				dto.setTimestamp(register.getTimestamp());
				
				dtos.add(dto);
			}
		}
		
		return dtos;
		
	}

}